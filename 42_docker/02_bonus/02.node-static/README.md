## How to use it

- Move the dockerfile in any nuxt-app
```cp -f Dockerfile ./appexample```

- Build de l'image
```docker build -t node-static .```

- Lancement du container
```docker run --rm -p 8000:80 node-static:latest```
