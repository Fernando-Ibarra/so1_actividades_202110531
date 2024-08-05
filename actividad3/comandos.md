# Actividad 3 - Control de accesos

### Parte 1: Gestión de Usuarios
```bash
# Crear usuarios
sudo adduser usuario1
sudo adduser usuario2
sudo adduser usuario3

# Establecer contraseñas
sudo passwd usuario1
New password: #myUser1024
Retype new password: #myUser1024
# output -> passwd: password updated successfully

sudo passwd usuario2
New password: # myUser2024
Retype new password: # myUser2024
# output -> passwd: password updated successfully

sudo passwd usuario3
New password: #myUser3024
Retype new password: #myUser3024
# output -> passwd: password updated successfully

# Mostrar información del usuario1
sudo id usuario1
# output -> uid=1001(usuario1) gid=1001(usuario1) groups=1001(usuario1)

# Eliminar usuario3 pero conservar su directorio personal
sudo userdel -r usuario3 
```

### Parte 2: Gestión de Grupos
```bash
# Crear grupos
sudo groupadd grupo1
sudo groupadd grupo2

# Agregar usuarios a los grupos
sudo usermod -aG grupo1 usuario1
sudo usermod -aG grupo2 usuario2

# Mostrar información de los grupos usando 'groups'
groups usuario1
# output -> usuario1 : usuario1 grupo1

groups usuario2
# output -> usuario2 : usuario2 grupo2

# Eliminar grupo2
sudo groupdel grupo2
```

### Parte 3: Gestión de Permisos
```bash
# Como `usuario1`, crea un archivo llamado `archivo1.txt` en su directorio principal y escribe algo en él.
su usuario1
cd 
touch archivo1.txt
echo "Archivo creado por el usuario1 para el curso de Sistemas Operativos 1" > archivo1.txt

# Crea un directorio llamado `directorio1` y dentro de ese directorio, un archivo llamado `archivo2.txt`.
mkdir directorio1
touch directorio1/archivo2.txt

# Verificar Permisos
ls -l
# output -> total 0
# output -> -rw-r--r--. 1 usuario1 usuario1 0 Aug  4 14:12 archivo2.txt

ls -ld
# output -> drwxr-xr-x. 1 usuario1 usuario1 24 Aug  4 14:12 .

# Modificar Permisos usando `chmod` con Modo Numérico
chmod 640 archivo1.txt

# Modificar Permisos usando `chmod` con Modo Simbólico
chmod u+x archivo2.txt

# Cambiar el Grupo Propietario
chgrp grupo1 archivo2.txt

# Configurar Permisos de Directorio
chmod 740 directorio1

# Comprobación de Acceso
su usuario2
cd
cat archivo1.txt
# output -> cat: archivo1.txt: Permission denied

# Verificación Final
ls -l
# output -> -rw-r-----. 1 usuario1 usuario1 70 Aug  4 14:05 archivo1.txt
# output -> drwxr-----. 1 usuario1 usuario1 24 Aug  4 14:12 directorio1
# output -> -rwxr--r--. 1 usuario1 grupo1 0 Aug  4 14:12 archivo2.txt

ls -ld
# output -> drwx------. 1 usuario1 usuario1 176 Aug  4 18:11 .
# output -> drwxr-----. 1 usuario1 usuario1 24 Aug  4 14:12 .
```