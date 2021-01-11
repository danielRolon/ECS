#include <load/loader.h>
#include <cstring>

unsigned int getTemplateIndex(json_t const* json, const char* name)
{
	unsigned int index;

	json_t const* templateJson = getPropertyCheck(json, "template", JSON_ARRAY);

	for (json_t const* child = getChildCheck(templateJson, JSON_OBJ); child != 0; child = getSiblingCheck(child, JSON_OBJ))
	{
		json_t const* propType = getPropertyCheck(child, "type", JSON_TEXT);
		json_t const* propIndex = getPropertyCheck(child, "index", JSON_INTEGER);

		if (strcmp(name, json_getValue(propType)) == 0)
		{
			index = atoi(json_getValue(propIndex));
			break;
		}
	}

	return index;

}