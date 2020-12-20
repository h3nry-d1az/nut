import json


def loadJSON(path:str, property:str) -> list:
	res = []
	with open(path) as content:
		loaded_json = json.load(content)
		for result in loaded_json:
			res.append(result.get(property))

	return res