#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

# load aliases
[[ -e $HOME/.bash_aliases ]] && . $HOME/.bash_aliases

f() {
	ranger
}

rose() {
	cat ~/.ascii_art/rose.txt
}

export EDITOR="vim"

# tbh i do not know what this does
tput smkx

# i know this is the prompt
PS1='\u \W \$ '
