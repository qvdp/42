FROM	ubuntu:latest

LABEL	maintainer="Quentin Van Der perre <qvan-der@42.student.fr>"

ARG		GITLAB_URL=https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh 
ARG		MACHINE_IP=192.168.99.100

RUN		apt-get update \
		&& apt-get upgrade -y \
		&& apt-get install -y --no-install-recommends curl openssh-server ca-certificates \
		&& curl -sS "${GITLAB_URL}" | bash \
		&& apt-get update \
		&& apt-get install -y gitlab-ce \
		&& apt update \
		&& apt install -y tzdata \
		&& apt-get clean \
		&& rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

RUN		mkdir -p /etc/gitlab/ssl \
		&& chmod 700 /etc/gitlab/ssl \
		&& openssl req -x509 -nodes -newkey rsa:4096 -days 365 -keyout /etc/gitlab/ssl/ssl.key -out /etc/gitlab/ssl/ssl.crt -subj /C=FR/ST=42/L=Paris/O=42/OU=Org/CN="${MACHINE_IP}" \
		&& echo "external_url \"https://${MACHINE_IP}\"" >> /etc/gitlab/gitlab.rb \
		&& echo "nginx['redirect_http_to_https'] = true" >> /etc/gitlab/gitlab.rb \
		&& echo "nginx['ssl_certificate'] = \"/etc/gitlab/ssl/ssl.crt\"" >> /etc/gitlab/gitlab.rb \
		&& echo "nginx['ssl_certificate_key'] = \"/etc/gitlab/ssl/ssl.key\"" >> /etc/gitlab/gitlab.rb

EXPOSE	443 80 22

ENTRYPOINT  service ssh start \
			&& (/opt/gitlab/embedded/bin/runsvdir-start &) \
			&& gitlab-ctl reconfigure \
			&& gitlab-ctl tail
