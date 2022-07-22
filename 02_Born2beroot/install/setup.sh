#!/bin/bash
# Define the USER variable as your 42 username.
read -p "Enter your 42 username: " USER

# Check if the current user is root, if it is not, exit.
if [ "$(whoami)" == "root" ] ; then
    echo "Starting the installation process..."
else
    echo "Please run as root (su) to proceed with the installation."
    exit
fi

# Update package repositories. This is used to knows which packages are available for upgrade, and where to retrieve that software.
apt update
# The sudo package configures basic rules for allowing unprivileged users to run commands as root or another user/group in the shell.
apt -y install sudo
# UFW is a frontend for managing firewall rules.
apt -y install ufw
# libpam-pwquality package provides some plug-in strength-checking for passwords.
apt -y install libpam-pwquality
# AppArmor proactively protects the operating system and applications from external or internal threats by enforcing a specific
# rule set on a per application basis.
apt -y install apparmor
#Cron allows the user to manage scheduled tasks from the command line.
apt -y install cron

# Manage files permissions.
chmod 644 sshd_config
chmod 644 login.defs
chmod 644 common-password
chmod 644 sudo_config
chmod 644 interfaces
chmod 600 root
chmod 644 monitoring.sh

# SSH config file (SSH root login disabled, SSH port changed to 4242).
cp sshd_config /etc/ssh/sshd_config
# Password expiration policy (password expires every 30 days, 2 days delay to modify a password, display a warning message 7 days before a password expires).
cp login.defs /etc/login.defs
# Password strength policy (password must be at least 10 characters long, have an uppercase letter and a number,
# must not contain more than 3 consecutive identical characters, must not include the name of the user).
cp common-password /etc/pam.d/common-password
# Sudo rules (authentications using sudo limited to 3 attempts, display a message if a password is wrong, each action of sudo is recorded in a log file,
# enable TTY mode, restrict paths that can be used by sudo).
cp sudo_config /etc/sudoers.d/sudo_config
# Set a static IP instead of DHCP (dynamic) addressing. This will disable the use of UDP port 68 initally open with DHCP.
cp interfaces /etc/network/interfaces
# Cron is used to display the bash monitoring script every 10 minutes. The "wall" command allows the script to be executed on all terminals.
cp root /var/spool/cron/crontabs/root
# The bash monitoring script.
cp monitoring.sh /usr/local/bin/monitoring.sh 

# Enable UFW and allow  SSH connections on port 4242.
ufw enable
ufw allow 4242

# Add a user42 group and add $USER to the user42 and sudo groups.
addgroup user42
adduser $USER user42
adduser $USER sudo

# Set sudo log directory permissions.
chmod 755 /var/log/sudo

# Set up password expiration for already created accounts.
chage -M 30 -m 2 -W 7 $USER
chage -M 30 -m 2 -W 7 root

# Display a message when installation is finished.
echo "Everything was successfully installed. Rebooting now."

# Clean after installation.
rm -rf sshd_config login.defs common-password sudo_config interfaces root monitoring.sh setup.sh

# Reboot the virtual machine
reboot
