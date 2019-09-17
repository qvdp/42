FROM	debian:latest

LABEL	maintener="Quentin VAN DER PERRE <qvan-der@student.42.fr>"

RUN	apt-get upgrade -y \
	&& apt update -y \
	&& apt-get install -y curl software-properties-common \
	&& curl -sL https://deb.nodesource.com/setup_10.x | bash \
	&& apt-get install -y nodejs vim git \
	&& curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg |apt-key add \
	&& echo "deb https://dl.yarnpkg.com/debian/ stable main" | tee /etc/apt/sources.list.d/yarn.list \
	&& apt update -y \
	&& apt-get install -y --no-install-recommends yarn 

WORKDIR /opt/app
