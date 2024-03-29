#
# ~/.bash_profile
#

source ~/.bashrc

export XDG_CONFIG_HOME=$HOME/.config
export XDG_CACHE_HOME=$HOME/.cache
export XDG_DATA_HOME=$HOME/.local/share
export EDITOR="vim"
export GOPATH="/home/alex/go"
export PATH=$PATH:$GOPATH:$GOPATH/bin

[[ -f ~/.bashrc ]] && . ~/.bashrc

# if systemctl -q is-active graphical.target && [[ ! $DISPLAY && $XDG_VTNR -eq 1 ]]; then
	# exec startx
# fi
