import json


def loadJSON(path:str, property:str) -> str:
	res = ""
	with open(path) as content:
		loaded_json = json.load(content)
		res = loaded_json.get(property)

	return res