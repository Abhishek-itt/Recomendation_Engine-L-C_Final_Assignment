-- Create the cafetarea database
CREATE DATABASE IF NOT EXISTS cafetarea;

-- Use the cafetarea database
USE cafetarea;

-- Create the Users table
CREATE TABLE IF NOT EXISTS Users (
    user_name VARCHAR(255) PRIMARY KEY,
    employee_id INT NOT NULL UNIQUE,
    user_type ENUM('Admin', 'Chef', 'Employee') NOT NULL,
    first_name VARCHAR(255) NOT NULL,
    last_name VARCHAR(255) NOT NULL
);

-- Create the Food_Items table
CREATE TABLE IF NOT EXISTS Food_Items (
    food_id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    food_name VARCHAR(255) NOT NULL,
    price INT UNSIGNED NOT NULL,
    is_available BOOL NOT NULL,
    description TEXT
);

-- Create the Food_Feedback table
CREATE TABLE IF NOT EXISTS Food_Feedback (
    feedback_id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    food_id INT UNSIGNED NOT NULL,
    user_name VARCHAR(255) NOT NULL,
    taste_rating INT NOT NULL,
    quality_rating INT NOT NULL,
    review TEXT,
    FOREIGN KEY (food_id) REFERENCES Food_Items(food_id),
    FOREIGN KEY (user_name) REFERENCES Users(user_name)
);

-- Create the Daily_Rollout table
CREATE TABLE IF NOT EXISTS Daily_Rollout (
    rollout_id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    date DATE NOT NULL,
    meal_type ENUM('breakfast', 'lunch', 'dinner') NOT NULL,
    food_id INT UNSIGNED NOT NULL,
    FOREIGN KEY (food_id) REFERENCES Food_Items(food_id)
);

-- Create the Rollout_Voting table
CREATE TABLE IF NOT EXISTS Rollout_Voting (
    voting_id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    rollout_id INT UNSIGNED NOT NULL,
    user_name VARCHAR(255) NOT NULL,
    FOREIGN KEY (rollout_id) REFERENCES Daily_Rollout(rollout_id),
    FOREIGN KEY (user_name) REFERENCES Users(user_name)
);

-- Create the Daily_Menu table
CREATE TABLE IF NOT EXISTS Daily_Menu (
    daily_menu_id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    food_id INT UNSIGNED NOT NULL,
    date DATE NOT NULL,
    FOREIGN KEY (food_id) REFERENCES Food_Items(food_id)
);

-- Create the Daily_Menu_Response table
CREATE TABLE IF NOT EXISTS Daily_Menu_Response (
    daily_menu_id INT UNSIGNED NOT NULL,
    user_name VARCHAR(255) NOT NULL,
    response ENUM('none', 'bad', 'neutral', 'good') NOT NULL,
    FOREIGN KEY (daily_menu_id) REFERENCES Daily_Menu(daily_menu_id),
    FOREIGN KEY (user_name) REFERENCES Users(user_name),
    PRIMARY KEY (daily_menu_id, user_name)
);

CREATE TABLE IF NOT EXISTS User_Notifications (
    notification_id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT,
    message TEXT NOT NULL,
    notifcation_type ENUM('rollout', 'menu_update', 'todays_food', 'feedback_request') NOT NULL, 
    user_name VARCHAR(255) NOT NULL,
    FOREIGN KEY (user_name) REFERENCES Users(user_name)
);

INSERT INTO Users (user_name, employee_id, user_type, first_name, last_name) VALUES
('john_doe', 1, 'Admin', 'John', 'Doe'),
('jane_smith', 2, 'Chef', 'Jane', 'Smith'),
('alex_jones', 3, 'Employee', 'Alex', 'Jones'),
('maria_garcia', 4, 'Employee', 'Maria', 'Garcia'),
('david_lee', 5, 'Chef', 'David', 'Lee');
