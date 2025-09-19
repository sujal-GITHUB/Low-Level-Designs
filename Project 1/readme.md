# Q&A System (Low-Level Design Implementation)

This project is a **C++ implementation of a Q&A system**, inspired by platforms like StackOverflow. It demonstrates **object-oriented design**, **class relationships**, and **basic system functionalities** such as posting questions, answering, commenting, voting, and tracking user reputation.

---

## Overview

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

## Key Learnings

- Applying **OOP principles** in system design.
- Implementing **Singleton pattern** for the central system.
- Modeling **relationships between classes**.
- Handling **user interactions** (questions, answers, comments, votes).
- Calculating **user reputation** based on activity.

---
## Future Enhancements

- **Advanced Reputation System**  
  Introduce more granular scoring, e.g., +10 for an upvote, -2 for a downvote, badges, and ranks for active users.  

- **Search & Filtering**  
  Implement search functionality to filter questions by tags, keywords, or popularity.  

- **Tag Management**  
  Allow users to create, follow, and organize tags to improve content discoverability.  

- **User Profiles & Activity Logs**  
  Each user could have a profile showing their questions, answers, comments, and reputation history.  

- **Accepting Answers**  
  Question askers can mark an answer as “accepted,” giving additional reputation to the answerer.  

- **Notifications System**  
  Users get notified when their question is answered, their answer is commented on, or they receive a vote.  

- **Persistence Layer**  
  Store data in a database or file system so that questions, answers, and users are retained across sessions.  

- **Concurrency & Scaling**  
  Enhance design to handle multiple users interacting simultaneously, mimicking real-world platforms.  

- **UI/UX Improvements**  
  Add a command-line interface (CLI) or web-based frontend for better user interaction.  
