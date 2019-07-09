FROM	nginx:latest

LABEL	maintener="Quentin VAN DER PERRE<qvan-der@student.42.fr>"

RUN	apt-get upgrade -y \
	&& apt update -y \
	&& apt-get install -y curl software-properties-common \
	&& curl -sL https://deb.nodesource.com/setup_10.x | bash \
	&& apt-get install -y nodejs

RUN	mkdir -p /opt/app
COPY 	. /opt/app
WORKDIR	/opt/app

RUN 	npm install \
	&& npm run generate \
	&& rm -rf /usr/share/nginx/html \
	&& mv ./dist /usr/share/nginx/html
