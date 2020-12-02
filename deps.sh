# nut deps installer for Linux
if [ $1 = "apt" ]; then
	sudo apt update
	sudo apt install gcc
	sudo apt install bison
	sudo apt install flex

elif [ $1 = "pacman" ];
	pacman -S gcc
	pacman -S bison
	pacman -S flex
fi