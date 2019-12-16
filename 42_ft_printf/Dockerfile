FROM	ubuntu:latest

LABEL	maintainer="Quentin VAN DER PERRE<qvan-der@student.42.fr>"

RUN		apt update \
			&& apt upgrade -y  \
			&& apt-get install -y build-essential vim git

WORKDIR /opt/app

COPY	. /opt/app

RUN		cd /opt/app \
			&& make re \

RUN		git clone https://github.com/jeremiemartel/ft_printf_checker.git
