## How to use it ?

- Build de l'image
```docker build -t ts-server .```

- Run du serveur
```docker run --rm -d -p 9987:9987/udp -p 1011:1011 -p 30033:30033 --env TS3SERVER_LICENSE=accept ts-server```

- Connection au server
```Start ts3 -> Connect 192.168.99.100:9987 -> Paste auth key```
