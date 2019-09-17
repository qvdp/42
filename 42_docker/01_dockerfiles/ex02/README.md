## How to use it ?

- Telechargement d'une app
```git clone https://github.com/qvdp/ft_rails.git app```

- Build de l'image de l'app `/ft-rails`
```docker build -t ft-rails:on-build .```

- Build de l'image du compilateur
```docker build -t rails-app .```

- Run de l'app
```docker run --rm -p 3000:3000 rails-app```
