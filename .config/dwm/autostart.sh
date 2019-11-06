wal -R
amixer sset "Master" 0
amixer sset "Master" mute
compton -c &
while xsetroot -name `date +%H:%M`; do
	sleep 0.5
done
