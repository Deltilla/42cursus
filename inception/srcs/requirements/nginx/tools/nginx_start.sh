#! /bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

mkdir -p /etc/nginx/ssl

if [ ! -f /etc/nginx/ssl/inception.crt ]; then
	echo -e "${GREEN}NGINX: Generando certificado SSL autofirmado...${NC}"
	openssl req -x509 -nodes -days 30 -newkey rsa:2048 \
		-keyout /etc/nginx/ssl/inception.key \
		-out /etc/nginx/ssl/inception.crt \
		-subj "/C=ES/ST=Andalucia/L=Málaga/O=42/OU=Inception/CN=${DOMAIN_NAME}"
fi

echo -e "${GREEN}NGINX: Arrancando el servidor...${NC}"

exec nginx -g "daemon off;"
