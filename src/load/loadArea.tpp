#include <load/loadArea.h>
#include <ec/sys/areaSys.h>
#include <tools/loader.h>
#include <tools/tinyjson.h>

template <>
inline void loadCmp<AreaComponent>(const char* path)
{
	// cargar json
	json_t const* json = loadJson(path);

	// obtener indice desde la plantilla
	unsigned int myIndex = getTemplateIndex(json, "area");


	// obtener componentes
	json_t const* componentsTemplate = getPropertyCheck(json, "components", JSON_ARRAY);

	int index = 0;
	// recorrer plantilla de componentes
	for (json_t const* child = getChildCheck(componentsTemplate, JSON_ARRAY); child != 0; child = getSiblingCheck(child, JSON_ARRAY))
	{
		if (index == myIndex) // si estamos en el index render
		{
			// recorrer componentes
			for (json_t const* cmp = getChildCheck(child, JSON_OBJ); cmp != 0; cmp = getSiblingCheck(cmp, JSON_OBJ))
			{
				// propiedades del componente
				json_t const* propID  = getPropertyCheck(cmp, "id", JSON_INTEGER);
				json_t const* propX   = getPropertyCheck(cmp, "x", JSON_INTEGER);
				json_t const* propY   = getPropertyCheck(cmp, "y", JSON_INTEGER);
				json_t const* propW   = getPropertyCheck(cmp, "w", JSON_INTEGER);
				json_t const* propH   = getPropertyCheck(cmp, "h", JSON_INTEGER);

				// datos del componente;
			    auto& areaCmp = createComponent<AreaComponent>(atoi(json_getValue(propID)));
			    areaCmp.x = atoi(json_getValue(propX));
			    areaCmp.y = atoi(json_getValue(propY));
			    areaCmp.w = atoi(json_getValue(propW));
			    areaCmp.h = atoi(json_getValue(propH));
			    areaCmp.collide = false;
			    areaCmp.lastCollide = false;

			    delete propID;
			    delete propX;
			    delete propY;
			    delete propW;
			    delete propH;
			}
			break;
		}
		index++;
	}
}