# To-Do-List

## English Description

This project is a task management application built using Qt and C++. It allows users to manage tasks by adding, removing, and completing them. The application **introduces the MVP (Model-View-Presenter)** design pattern for the first time in the code, aiming for better code maintainability and separation of concerns, although there might still be some imperfections in its implementation.

### Technologies Used
- **Qt**: A powerful cross-platform framework used for the development of the graphical user interface (GUI).
- **C++**: The programming language used for the core logic and application flow.
- **MVP Pattern**: The application **introduces the MVP design pattern** for the first time, with an intention to clearly separate the model, view, and presenter, though it might not be fully perfected.

### Features
- **Task Management**: Add, remove, and complete tasks with a simple interface.
- **Customizable Views**: The application supports dynamic updates to the task list and user interface.
- **Cross-Platform Support**: Built with Qt, the application runs on various platforms, including Windows and Linux.

### Design and Architecture
The architecture of the application is divided into three main components:
1. **Model**: Represents the data structure and business logic.
2. **View**: Displays the user interface and user interactions.
3. **Controller**: Handles communication between the model and view, aiming for a clear separation of concerns, though the implementation may still need refinement.
4. **Managers**: The application uses both **general and local managers**, which ensure communication between different views and models. Managers send signals to update data in models and simultaneously update views to reflect those changes. They can also handle background tasks, such as processing data in separate threads, ensuring the interface remains responsive.

---

## Описание на русском

Этот проект представляет собой приложение для управления задачами, разработанное с использованием Qt и C++. Оно позволяет пользователям управлять задачами, добавлять, удалять и завершать их. В приложении **впервые используется паттерн проектирования MVP (Model-View-Presenter)** с целью улучшения поддерживаемости кода и разделения обязанностей, хотя его реализация может иметь некоторые недочёты.

### Используемые технологии
- **Qt**: Мощный кросс-платформенный фреймворк, использующийся для разработки графического интерфейса (GUI).
- **C++**: Язык программирования, используемый для основной логики и работы приложения.
- **Паттерн MVP**: В приложении **впервые используется паттерн MVP**, с намерением чётко разделить модель, представление и презентер, хотя его реализация может быть ещё не до конца отшлифована.

### Возможности
- **Управление задачами**: Добавление, удаление и завершение задач с помощью простого интерфейса.
- **Настраиваемые представления**: Приложение поддерживает динамическое обновление списка задач и пользовательского интерфейса.
- **Кросс-платформенность**: Благодаря использованию Qt, приложение работает на различных платформах, включая Windows и Linux.

### Дизайн и архитектура
Архитектура приложения разделена на три основные компонента:
1. **Модель**: Представляет структуру данных и бизнес-логику.
2. **Представление**: Отображает пользовательский интерфейс и взаимодействие с пользователем.
3. **Контроллер**: Обрабатывает взаимодействие между моделью и представлением, стремясь к чёткому разделению обязанностей, хотя реализация может требовать доработки.
4. **Менеджеры**: В приложении используются как **общие, так и локальные менеджеры**, которые обеспечивают взаимодействие между различными представлениями и моделями. Менеджеры отправляют сигналы для обновления данных в моделях и одновременно обновляют представления, чтобы отобразить эти изменения. Они также могут выполнять задачи, связанные с фоновыми операциями, такими как обработка данных в отдельных потоках, что позволяет интерфейсу оставаться отзывчивым.
