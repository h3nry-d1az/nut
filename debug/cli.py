import config


def Config(args:list) -> None:
	splitted_args = [] #Starts as None

	for arg in args:
		splitted_args.append(arg.split('='))

	for element in splitted_args:
		if element[0] == 'user':
			config.user = element[1]
		if element[0] == 'password':
			config.password = element[1]
		if element[0] == 'machine':
			config.machine = element[1]
		if element[0] == 'image':
			config.image = element[1]
		if element[0] == 'flags':
			config.flags = element[1]