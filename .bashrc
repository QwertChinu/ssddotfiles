#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls --color=auto'
PS1='[\u@\h \W]\$ '
set -o vi
export VISUAL=nvim
export EDITOR="$VISUAL"
export MANPAGER="nvim -c 'set ft=man' -"

export SPARK_HOME='/home/chinu/spark-3.3.0-bin-hadoop3'
export PATH=$SPARK_HOME:$PATH
export PYTHONPATH=$SPARK_HOME/python:$PYTHONPATH
export PYSPARK_DRIVER_PYTHON="jupyter"
export PYSPARK_DRIVER_PYTHON_OPTS="notebook"
export PYSPARK_PYTHON=python3

set editing-mode vi
set show-mode-in-prompt on
set vi-ins-mode-string +
set vi-cmd-mode-string :
[ "$(tty)" = "/dev/tty1" ] && ! pgrep -x dwm >/dev/null && exec startx 

neofetch
alias v="nvim"
alias brc="v ~/.bashrc"
alias p="sudo pacman"
alias ll="ls -alh"
alias SS="sudo systemctl"
alias bkp="sudo timeshift-gtk"
alias ytc="yt-dlp --rm-cache-dir"
alias yt="yt-dlp --add-metadata -i -o '%(upload_date)s-%(title)s.%(ext)s'"
#alias yt="youtube-dl --add-metadata -i -o '%(upload_date)s-%(title)s.%(ext)s'"
alias yta="yt -x -f bestaudio/best"
alias ytf="yt-dlp -F"
alias py="python"
alias tp="ping 8.8.8.8"
alias rw="SS restart NetworkManager"
alias upkg="paru -Syyy && updblocks 36"
alias updm="sudo reflector --verbose --latest 10 --protocol http --protocol https --sort rate --save /etc/pacman.d/mirrorlist && upkg"
alias upd="updm && paru -Qqe > ~/.local/bin/pkg && cfg commit -am 'Arch System update' && cfg push ; pass git push ;sudo rsync -aAXv /home/chinu/.password-store/ /home/chinu/Dropbox/Secure/ps/ && bkp && paru -Syu && sudo journalctl --vacuum-time=2d && paru -Sc && sudo fstrim -a -v && updblocks 36 && updblocks 37 && updblocks 38"
alias r="ranger"
alias gv="cd ~/Downloads/video/"
alias tsmm="watch -n 10 transmission-remote -l"
alias tsm="transmission-remote"
alias tsmd="transmission-daemon --download-dir $HOME/Downloads/video"
alias tsmr="transmission-remote -l | grep 100\% | grep Done | awk '{print $1}' | xargs -n 1 -I \% /usr/bin/transmission-remote -t \% -r"
alias vrc="v ~/.config/nvim/init.vim"
alias mo="xset dpms force off"
alias fboot="sudo grub-mkconfig -o /boot/grub/grub.cfg"
alias play="mpv --ytdl-format=137+251"
alias cfg='/usr/bin/git --git-dir=/home/chinu/.cfg/ --work-tree=/home/chinu'
alias cssh="ssh 'chinu@192.168.1.105'"
alias kf="xmodmap ~/.local/bin/keys_disable"
alias fcaps="setxkbmap -option caps:escape"
alias mb7="sudo mount /dev/sdb7 /mnt && sudo ranger ~/Downloads/video/"
alias ma7="sudo mount /dev/sda7 /mnt && sudo ranger ~/Downloads/video/"
alias smc="sudo mount /dev/sdc1 /media && sudo ranger"
alias fm="xset s off && xset -dpms"
se() { du -a ~/.local/bin/ | awk '{print $2}' | fzf | xargs -r nvim; }
sm() { sudo mount /dev/sdb7 /mnt && du -a /mnt/Movies/ | awk '{print $2}' | fzf | xargs -r mpv; }
