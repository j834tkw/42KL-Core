#!/bin/bash

# install wp-cli
# move it to /usr/local/bin to make it globally accessible as wp
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
echo "Downloaded and moved wp-cli.phar"

# creates wordpress directory & sets permissions
mkdir /var/www/wordpress
cd /var/www/wordpress
chmod -R 755 /var/www/wordpress/
chown -R www-data:www-data /var/www/wordpress
echo "Created wordpress directory at /var/www/wordpress/"

# sleep 7

# download core wordpress files
wp core download --allow-root

# create wp-config.php file with database connection settings
wp core config --dbhost=mariadb:3306 --dbname="${MYSQL_DB}" --dbuser="${MYSQL_USER}" --dbpass="${MYSQL_PASSWORD}" --allow-root

# install wordpress
wp core install --url="${DOMAIN_NAME}" --title="${WP_TITLE}" --admin_user="${WP_ADMIN_USER}" --admin_password="${WP_ADMIN_PASS}" --admin_email="${WP_ADMIN_EMAIL}" --allow-root

# create new user
wp user create "${WP_USER}" "${WP_EMAIL}" --user_pass="${WP_PASS}" --allow-root

# configure listening port from unix socket to port 9000
sed -i '36 s@/run/php/php7.4-fpm.sock@9000@' /etc/php/7.4/fpm/pool.d/www.conf

# create directory for php-fpm runtime files
mkdir -p /run/php

# start php-fpm service in the foreground and as root
echo "php-fpm will now run in foreground..."
/usr/sbin/php-fpm7.4 -F -R