#include<bits/stdc++.h>
using namespace std;

static int question_number = 1;
static int answer_number = 1;
static int user_number = 1;

class Answer;
class Question;
class User;

class System{
    set<Question* >questions;
    set<Answer* >answers;
    unordered_map<Question*, vector<Answer* >>QuestionToAnswer;
    unordered_map<Answer*, Question* >AnswerToQuestion;
    set<User* >users;

    System(){
        cout<<"System Up!"<<endl;
    }

    System(const System&) = delete;
    System& operator= (const System&) = delete;

    public:

    static System& getInstance(){
        static System instance;
        return instance;
    }

    void addUser(User* user){
        users.insert(user);
    }

    void deleteUser(User* user){
        users.erase(user);
    }

    void addQuestion(Question* question){
        questions.insert(question);
        cout<<"Question added in system!"<<endl;
    }

    void deleteQuestion(Question* question){
        auto qIt = questions.find(question);
        if (qIt != questions.end()) {
            questions.erase(qIt);
        }

        // Remove all answers linked to this question
        if(QuestionToAnswer.count(question)){
            for(auto ans: QuestionToAnswer[question]) {
                answers.erase(ans);
                auto it = AnswerToQuestion.find(ans);
                if(it != AnswerToQuestion.end()) {
                    AnswerToQuestion.erase(it);
                }
            }
            QuestionToAnswer.erase(question);
        }
    }

    void addAnswer(Question* question, Answer* answer){
        auto q = questions.find(question);
        if(q == questions.end()){
            cout<<"Question not found!"<<endl;
        }

        answers.insert(answer);
        QuestionToAnswer[question].push_back(answer);
        AnswerToQuestion[answer] = question;
    }

    void deleteAnswer(Answer* answer) {
        auto a = answers.find(answer);
        if (a == answers.end()) {
            cout << "Answer not found!" << endl;
            return;
        }

        answers.erase(a);

        auto it = AnswerToQuestion.find(answer);
        if(it != AnswerToQuestion.end()) {
            Question* q = it->second;
            auto& vec = QuestionToAnswer[q];
            vec.erase(remove(vec.begin(), vec.end(), answer), vec.end());
            if (vec.empty()) {
                QuestionToAnswer.erase(q);
            }
            AnswerToQuestion.erase(it);
        }
    }

    Question* getQuestion(int questionNumber);

    Answer* getAnswer(int answerId);

    vector<Answer* > getAnswersForQuestion(Question* question){
        for(auto it: QuestionToAnswer){
            if(QuestionToAnswer.count(it.first) > 0){
                return it.second;
            }
        }

        cout<<"Question not found!"<<endl;
        return {};
    }

    Question* getQuestionForAnswer(Answer* answer){
        for(auto it: AnswerToQuestion){
            if(AnswerToQuestion.count(it.first) > 0){
                return it.second;
            }
        }

        cout<<"Question not found!"<<endl;
        return {};
    }

    //1 question -> *100
    //1 answer -> *500
    int getReputationScore(User* user);
};

class Question{
    int questionId;
    int votes;
    set<string>tags;
    string question;
    vector<Answer* >answers;
    vector<string>comments;

    public:

    Question(string question){
        this->questionId = question_number++;
        this->question = question;
    }

    void addTag(string tag){
        this->tags.insert(tag);
    }

    void upVote(){
        this->votes++;
    }

    void downVote(){
        this->votes--;
    }

    int getQuestionId(){
        return this->questionId;
    }

    vector<Answer* > getAnswers(){
        return this->answers;
    }

    void addComment(string comment){
        this->comments.push_back(comment);
    }
};

class Answer{
    int answerId;
    string answer;
    Question* question;
    int votes;
    vector<string>comments;

    public:

    int getAnswerId(){
        return this->answerId;
    }

    Answer(string answer, Question* question){
        this->answerId = answer_number++;
        this->answer = answer;
        this->question = question;
    }

    Question* getQuestion(){
        return this->question;
    }

    void upVote(){
        this->votes++;
    }

    void downVote(){
        this->votes--;
    }

    void addComment(string comment){
        this->comments.push_back(comment);
    }
};

class User {
    int userId;
    string username;
    int reputationScore;
    set<Question*> questionsPosted;
    set<Answer*> AnswersPosted;
    System& system = System::getInstance();

public:
    User(string username){
        this->userId = user_number++;
        this->username = username;
        reputationScore = 0;
    }

    int getUserId() {
        return this->userId;
    }

    vector<Question*> getQuestions() {
        vector<Question*> ques(this->questionsPosted.begin(), this->questionsPosted.end());
        return ques;
    }

    vector<Answer*> getAnswers() {
        vector<Answer*> ans(this->AnswersPosted.begin(), this->AnswersPosted.end());
        return ans;
    }

    int getReputationScore() {
        return this->reputationScore;
    }

    void postQuestion(int questionNumber, string questionText) {
        Question* ques = new Question(questionText);
        questionsPosted.insert(ques);
        system.addQuestion(ques);
        cout << "Question Posted!" << endl;

        int reputation = system.getReputationScore(this);
        this->reputationScore = reputation;
    }

    void answerQuestion(int questionNumber, string answerText) {
        Question* question = system.getQuestion(questionNumber);

        Answer* ans = new Answer(answerText, question);
        AnswersPosted.insert(ans);
        system.addAnswer(question, ans);
        cout<< "Answer Posted!" << endl;

        int reputation = system.getReputationScore(this);
        this->reputationScore = reputation;
    }

    void commentOnQuestion(int questionNumber, string comment){
        Question* question = system.getQuestion(questionNumber);

        question->addComment(comment);
        cout<<"Comment added"<<endl;
    }

    void commentOnAnswer(int answerNumber, string comment){
        Answer* answer = system.getAnswer(answerNumber);

        answer->addComment(comment);
        cout<<"Comment added"<<endl;
    }

    void upVoteQuestion(int questionId){
        Question* question = system.getQuestion(questionId);
        question->upVote();
    }

    void upVoteAnswer(int answerId){
        Answer* answer = system.getAnswer(answerId);
        answer->upVote();
    }

    void downVoteQuestion(int questionId){
        Question* question = system.getQuestion(questionId);
        question->downVote();
    }

    void downVoteAnswer(int answerId){
        Answer* answer = system.getAnswer(answerId);
        answer->downVote();
    }
};

int System::getReputationScore(User* user){
    int answers = user->getAnswers().size();
    int questions = user->getQuestions().size();

    return answers*500 + questions*100;
}

Question* System::getQuestion(int questionNumber) {
        for (auto q : questions) {
            if (q->getQuestionId() == questionNumber) {
                return q;
            }
        }
        cout << "Question not found!" << endl;
        return nullptr;
    }

Answer* System::getAnswer(int answerId){
        for(auto a: answers){
            if(a->getAnswerId() == answerId){
                return a;
            }
        }
        cout<<"Answer not found!"<<endl;
        return nullptr;
    }

int main() {
    System& system = System::getInstance();

    // Create Users
    User* u1 = new User("Alice");
    User* u2 = new User("Bob");
    User* u3 = new User("Charlie");

    system.addUser(u1);
    system.addUser(u2);
    system.addUser(u3);

    // Alice posts a question
    u1->postQuestion(question_number, "What is polymorphism in C++?");
    Question* q1 = system.getQuestion(1);
    q1->addTag("C++");
    q1->addTag("OOP");

    // Bob posts a question
    u2->postQuestion(question_number, "What is the difference between TCP and UDP?");
    Question* q2 = system.getQuestion(2);
    q2->addTag("Networking");
    q2->addTag("Protocols");

    // Charlie answers Alice's question
    u3->answerQuestion(1, "Polymorphism allows methods to have different implementations based on context.");
    // Alice answers Bob's question
    u1->answerQuestion(2, "TCP is connection-oriented while UDP is connectionless.");

    // Comments
    u2->commentOnQuestion(1, "Great question!");
    u1->commentOnAnswer(1, "Nice explanation.");

    // Voting
    u2->upVoteQuestion(1);
    u3->upVoteAnswer(1);
    u1->downVoteQuestion(2);

    // Show reputation
    cout << "Alice Reputation: " << u1->getReputationScore() << endl;
    cout << "Bob Reputation: " << u2->getReputationScore() << endl;
    cout << "Charlie Reputation: " << u3->getReputationScore() << endl;

    // More answers
    u2->answerQuestion(1, "It means same function name with different behavior.");
    u3->answerQuestion(2, "UDP is faster but unreliable, TCP guarantees delivery.");

    // Add comments on Q/A
    u1->commentOnQuestion(2, "I think you should also mention reliability.");
    u2->commentOnAnswer(2, "Thanks Alice!");

    // Upvote & Downvote
    u1->upVoteAnswer(3);
    u3->downVoteAnswer(2);

    // Print updated reputations
    cout << "Alice Reputation: " << u1->getReputationScore() << endl;
    cout << "Bob Reputation: " << u2->getReputationScore() << endl;
    cout << "Charlie Reputation: " << u3->getReputationScore() << endl;

    return 0;
}
