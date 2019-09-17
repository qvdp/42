## How to use it ?

- Creation d'une machine plus puissante
```docker-machine create --driver virtualbox --virtualbox-memory "4096" --virtualbox-cpu-count "2" Char```

- Build de l'image
```docker build --build-arg MACHINE_IP=$(docker-machine ip Char) -t gitlab .```

- Run de gitlab
```docker run --rm -it -p 8080:80 -p 4443:443 -p 2222:22 gitlab```

- Create password + create test user + create repo +  Clone d'un repo
```env GIT_SSL_NO_VERIFY=true git clone https://$(docker-machine ip Char):4443/test/test.git```

- Push sur un repo
```env GIT_SSL_NO_VERIFY=true git push```

- Clone SSH (penser a ajouter la cle ssh `cat ~/.ssh/id_rsa.pub` )
```env GIT_SSH_COMMAND='ssh -p 2222' git clone git@$(docker-machine ip Char):test/test.git```

- Push ssh
```env GIT_SSH_COMMAND='ssh -p 2222' git push```
