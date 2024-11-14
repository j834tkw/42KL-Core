#!/bin/bash

# create database
# create user and grant all permissions
# FLUSH PRIVILEGES to reload grant tables (contains information about users and their privileges)
echo "
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DB}\`;
CREATE USER IF NOT EXISTS \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${MYSQL_DB}\`.* TO \`${MYSQL_USER}\`@'%';
FLUSH PRIVILEGES;
" > init.sql

# initializes the database according to init.sql
# --bootstrap is used to run the SQL commands directly without starting the server
mysqld --bootstrap < init.sql

# allows mariadb to listen on port 3306 by uncommenting the line '# port = 3306'
sed -i "s/# port = 3306/port = 3306/" /etc/mysql/my.cnf

# makes mariadb accessible from any IP address
sed -i "s/127.0.0.1/0.0.0.0/" /etc/mysql/mariadb.conf.d/50-server.cnf

# launches mariadb with safety features
echo "mariadb will be launched using mysqld_safe..."
mysqld_safe
