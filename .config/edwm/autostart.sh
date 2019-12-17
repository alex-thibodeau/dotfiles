#!/bin/env bash

wal -R
amixer sset "Master" 0
amixer sset "Master" mute
[[ -f ~/.bash_profile ]] && . ~/.bash_profile
picom &
