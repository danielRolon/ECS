#include <load/loadRender.h>
#include <ec/sys/rensys.h>
#include <tools/loader.h>
#include <iostream>
#include <fstream>
#include <string.h>

#include <tools/tinyjson.h>

template <>
inline void loadCmp<RendererComponent>(const char* path)
{
	// cargar json
	json_t const* json = loadJson(path);

	// obtener indice desde la plantilla
	unsigned int myIndex = getTemplateIndex(json, "renderer");


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
				json_t const* propRGB = getPropertyCheck(cmp, "rgb", JSON_OBJ);

				// datos del componente;
			    auto& renCmp = createComponent<RendererComponent>(atoi(json_getValue(propID)));
			    renCmp.x = atoi(json_getValue(propX));
			    renCmp.y = atoi(json_getValue(propY));
			    renCmp.w = atoi(json_getValue(propW));
			    renCmp.h = atoi(json_getValue(propH));
			    renCmp.rgb;

				renCmp.rgb.R = atoi( json_getValue(getPropertyCheck(propRGB, "r", JSON_INTEGER)) );
				renCmp.rgb.G = atoi( json_getValue(getPropertyCheck(propRGB, "g", JSON_INTEGER)) );
			    renCmp.rgb.B = atoi( json_getValue(getPropertyCheck(propRGB, "b", JSON_INTEGER)) );

			    delete propID;
			    delete propX;
			    delete propY;
			    delete propW;
			    delete propH;
			    delete propRGB;
			}
			break;
		}
		index++;
	}
}