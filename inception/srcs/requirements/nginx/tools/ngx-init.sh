#!bin/bash

# -subj: allows the use of env variables
# -x509: specifies this is a self-signed X.509 cert
# -nodes: ensures private key file is not encrypted
# -days: sets cert’s validity period
# -newkey rsa:2048: generates new RSA private key with 2048-bit encryption
# -keyout: specifies where to save private key
# -out: specifies where to save cert
openssl req -subj "/C=$C/ST=$ST/L=$L/O=$O/OU=$OU/CN=$CN/emailAddress=$EMAILADDRESS" \
  -x509 -nodes -days 365 -newkey rsa:2048 \
  -keyout /etc/ssl/private/nginx-selfsigned.key  \
  -out /etc/ssl/certs/nginx-selfsigned.crt;

# "daemon off" starts nginx in foreground
echo "nginx will now run in the foreground..."
nginx -g 'daemon off;';