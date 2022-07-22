<h1 align="center">
	Born2beRoot
</h1>

<p align="center">
	<img src="https://user-images.githubusercontent.com/91064070/147373484-5f9d6a42-38d3-459b-89c3-24ea6e96c580.png?raw=true" alt="Sublime's custom image"/>
</p>

## Result

![](result.png)

## Install

### Create your Virtual Machine using VirtualBox

1. Install and launch VirtualBox.
2. Click on "New".
3. Name: Born2beRoot, Type: Linux, Version: Debian (64-bit).
4. Memory size: 1024 MB.
5. Create a virtual hard disk now.
6. VDI (VirtualBox Disk Image).
7. Dynamically allocated.
8. Size: 8,00 GB.
	
### Install Debian

1. [Download](https://www.debian.org/download) the Debian ISO file.
2. Select your virtual machine (VM) and click on "Start".
3. Select the Debian ISO file.
5. Graphical install.
6. Language: English.
7. Location: Unisted States.
8. Keyboard: French.
9. Hostname: your42username42.
10. Skip the domain name.
11. Define the root password.
12. Skip the full name.
13. Username: your42username.
14. Define username password.
15. Select whatever time zone.

### Partition Disk (Including Bonus Part)

1. Manual, SCSI, Yes.
2. pri/log, Create a new partition, 500 MB, Primary, Beginning, Use as: Ext4, Mount point: /boot, Done.
3. pri/log, Create a new partition, max, Logical, Use as: Ext4, Mount point: Do not mount it, Done.
4. Configure encrypted volumes, Yes, Create encrypted volumes, sda5, Done, Finish, Yes, Cancel, Define an encryption passphrase.
5. Configure the Logical Volume Manager, Yes, Create volume group, LVMGroup, sda5.
6. Create logical volume, LVMGroup.
	* root - 2 GB - Use as: Ext4 - Mount point: /
	* swap - 1024 MB - Use as: swap area
	* home - 1 GB - Use as: Ext4 - Mount point: /home
	* var - 1 GB - Use as: Ext4 - Mount point: /var
	* srv - 1 GB - Use as: Ext4 - Mount point: /srv
	* tmp - 1 GB - Use as: Ext4 - Mount point: /tmp
	* var-log - 1056 MB - Use as: Ext4 - Mount point: Enter manually: /var/log
6. Finish partitioning and write changes to disk, Yes, No, United States, deb.debian.org, Skip the HTTP proxy information, No, Uncheck "SSH server" and "Standard system utilities", Yes, sda.

### Set Up your Virtual Machine

1. Start your VM and login as root.
2. Run `apt -y install openssh-server`.
3. Run `vi /etc/ssh/sshd_config` and uncomment the Port 22 line and replace 22 by 4242.
4. In VirtualBox go to: Devices, Network, Network Settings, Advanced, Port Forwarding.
5. Add the following rule: Name: SSH, Protocol: TCP, Host IP: 127.0.0.1, Host Port: 1024, Guest IP: 10.0.2.15, Guest Port: 4242.
6. On your VM run `systemctl restart sshd` to restart the SSH service.
7. Clone this repo and run `cd 42-Born2beRoot/install`.
8. Open your terminal and run `scp -P 1024 * your42username@127.0.0.1:/tmp` then enter your password.
9. Go back to your VM and run `cd /tmp && bash setup.sh` to execute the setup script. Enter your 42username and wait untill the installation is finished and the server is restarted.
10. Once installation is completed don't forget to change the root and 42username account's password by running `passwd <username>`.

### Retrieve Signature of your Machine’s Virtual Disk (cf. [`subject`](Born2beRoot.pdf))
* On macOS or GNU/Linux open Terminal then run `cd ~/VirtualBox VMs/Born2beRoot && sha1sum Born2beRoot.vdi`.
* On Windows press `Windows + R` and type `cmd` to open a command prompt then run `cd C:\Users\<username>\VirtualBox VMs\Born2beRoot & certUtil -hashfile Born2beRoot.vdi sha1`.

## Useful Commands

### System

```shell
# Run an interactive shell as root:
su

# Run a command as the superuser (by default) or another user:
sudo <command>

# Check Debian version:
hostnamectl
cat /etc/os-release

# List information about block devices:
lsblk

# List installed packages:
dpkg -l
```

### Network

```shell
# Show information for all addresses:
ip addr

# List all of the route entries in the kernel:
route -n

# Enable SSH service: 
systemctl enable ssh

# Start SSH service:
systemctl start ssh

# Show SSH serivce status:
systemctl status ssh

# Restart SSH service:
systemctl restart ssh

# Check opened ports:
ss -tulpn

# Show used SSH port:
grep Port /etc/ssh/sshd_config

# Enable UFW:
ufw enable

# Allow 4242 port:
ufw allow 4242

# Show UFW rule(s) by number(s):
ufw status numbered

# Delete numbered UFW rule:
ufw delete <rulenumber>

# Connect to SSH server on port 4242:
ssh <login>@<IPAddress> -p 4242

# Exit session:
exit

# Show authentication related events: 
tail -f /var/log/auth.log | grep ssh
```

### User and Group

```shell
# Add user:
adduser <username>

# Show user's details:
getent passwd <username>

# Delete user:
deluser <username>

# Change user's password:
passwd <username>

# Switch user:
su <username>

# Check user's password policy:
chage -l <username>

# Add group:
addgroup <groupname>

# Delete group:
delgroup <groupname>

# Add user to group:
adduser <username> <groupname>

# Show group's informations:
getent group <group>

# Show user's group(s):
groups <username>

# Show avalaible groups:
getent group

# Check all local users:
cut -d: -f1 /etc/passwd

# Check current hostname:
hostnamectl

# Change hostname:
hostnamectl set-hostname <hostname>

# Modify hosts file: 
vi /etc/hosts
```

### Cron

```shell
# Show cron table content:
crontab -l

# Edit cron file: 
crontab -e

# Disable cron:
systemctl disable cron
/etc/init.d/cron stop
```
