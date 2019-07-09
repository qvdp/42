FROM	ubuntu:14.04

LABEL	maintainer="Quentin Van Der perre <qvan-der@42.student.fr>"

ENV	DEBIAN_FRONTEND=noninteractive
ENV	EXTERNAL_URL="localhost"

ARG	GITLAB_URL=https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh

RUN	apt update \
	&& apt upgrade -y \
	&& apt install -yq --no-install-recommends curl openssh-server ca-certificates apt-transport-https \
	&& apt install -y tzdata \
	&& apt-get clean \
	&& rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* \
	&& curl -sS "${GITLAB_URL}" | bash

EXPOSE	443
EXPOSE	80
EXPOSE	22
