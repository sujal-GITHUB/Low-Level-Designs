# Q&A System (Low-Level Design Implementation)

This project is a **C++ implementation of a Q&A system**, inspired by platforms like StackOverflow. It demonstrates **object-oriented design**, **class relationships**, and **basic system functionalities** such as posting questions, answering, commenting, voting, and tracking user reputation.

---

## 📖 Overview

The system models a Q&A platform with the following entities:

- **User**: Can post questions, answer questions, comment, and vote.
- **Question**: Contains the question text, tags, votes, comments, and related answers.
- **Answer**: Contains answer text, votes, comments, and links to its question.
- **System**: Singleton class that manages users, questions, answers, and mappings between them.

Key features implemented:

- Add, delete, and retrieve users, questions, and answers.
- Users can post questions and answers.
- Users can comment on questions and answers.
- Voting system for questions and answers (upvote/downvote).
- Reputation calculation:
  - 1 question → +100 points  
  - 1 answer → +500 points  

---

## 🎯 Key Learnings

- Applying **OOP principles** in system design.
- Implementing **Singleton pattern** for the central system.
- Modeling **relationships between classes**.
- Handling **user interactions** (questions, answers, comments, votes).
- Calculating **user reputation** based on activity.

---

## 🤝 Contribution

Contributions are welcome! You can:

- Add new functionalities like search, tags filtering, or answer ranking.
- Improve existing code structure or add additional design patterns.
- Write more comprehensive test cases and examples.

---

## 📜 License

This repository is **open-source** and free to use for learning and practice.
