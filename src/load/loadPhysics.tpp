#include <load/loadPhysics.h>
#include <ec/sys/physys.h>
#include <tools/loader.h>
#include <iostream>
#include <fstream>
#include <string.h>

#include <tools/tinyjson.h>

template <>
inline void loadCmp<PhysicsComponent>(const char* path)
{
	// cargar json
	json_t const* json = loadJson(path);

	// obtener indice desde la plantilla
	unsigned int myIndex = getTemplateIndex(json, "physics");


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
				json_t const* propVX   = json_getProperty(cmp, "vx");//JSON_REAL
				json_t const* propVY   = getPropertyCheck(cmp, "vy", JSON_INTEGER);

				// datos del componente;
			    auto& phyCmp = createComponent<PhysicsComponent>(atoi(json_getValue(propID)));
			    phyCmp.x = atof(json_getValue(propX));
			    phyCmp.y = atof(json_getValue(propY));
			    phyCmp.w = atof(json_getValue(propW));
			    phyCmp.h = atof(json_getValue(propH));
			    phyCmp.vx = atof(json_getValue(propVX));
			    phyCmp.vy = atof(json_getValue(propVY));

			    delete propID;
			    delete propX;
			    delete propY;
			    delete propW;
			    delete propH;
			    delete propVX;
			    delete propVY;
			}
			break;
		}
		index++;
	}
}