## How to use it ?

- Build de l'image
```docker build -t node-env .```

- Lancement du contnainer
```docker run -it -p 8000:8080 -v $(pwd):/opt/app node-env```
