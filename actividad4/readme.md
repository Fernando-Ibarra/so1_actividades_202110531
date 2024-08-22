# Create a Systemd service

1. Create a bash file to run the script on the service
```bash
#!/bin/bash

while true; do
    echo "Hello! The current date is $(date)"
    sleep 1
done
```

2. Create a service file in /etc/systemd/system/ folder
```bash
[Unit]
Description=Hello and Date Service
After=network.target

[Service]
ExecStart=/home/fernando/Documentos/University/so1_actividades_202110531/actividad4/hello.sh
Restart=always
RestartSec=5

[Install]
WantedBy=multi-user.target
```
3. Make execute the bash file
```bash
chmod +x hello.sh
```

4. Reload the systemd daemon
```bash
sudo systemctl daemon-reload
```

5. Enable and start the service
```bash
sudo systemctl enable hello.service
sudo systemctl start hello.service
```

6. Check the status of the service
```bash
sudo systemctl status hello.service
```

7. Checks the logs of the service
```bash
journalctl -u hello.service -f

Example:
```bash
sudo journalctl -u hello.service -f
ago 21 20:15:32 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:32 CST
ago 21 20:15:33 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:33 CST
ago 21 20:15:34 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:34 CST
ago 21 20:15:35 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:35 CST
ago 21 20:15:36 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:36 CST
ago 21 20:15:37 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:37 CST
ago 21 20:15:38 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:38 CST
ago 21 20:15:39 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:39 CST
ago 21 20:15:40 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:40 CST
ago 21 20:15:41 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:41 CST
ago 21 20:15:42 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:42 CST
ago 21 20:15:43 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:43 CST
ago 21 20:15:44 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:44 CST
ago 21 20:15:45 ferbuntu hello.sh[13464]: Hello! The current date is mié 21 ago 2024 20:15:45 CST
^C
```


8. Stop the service
```bash
sudo systemctl stop hello.service
```