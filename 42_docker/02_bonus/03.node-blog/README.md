## How to use it ?

- Build de l'image
```docker image build -t node-blog .```

- Lancement du contnainer
```docker run --rm -d -p 3000:1340 -v $(pwd):/var/lib/ghost/content node-blog```
