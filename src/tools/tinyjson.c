#include <tools/tinyjson.h>
#include <tools/loader.h>

// Carga un archivo y retorna un json_t
json_t const* loadJson(const char* path)
{
	char* text = const_cast<char*>(loadFile(path));
    json_t mem[512];
    json_t const* json = json_create( text, mem, sizeof mem / sizeof *mem );

    if ( !json ) {
        puts("Error json create.");
        exit(EXIT_FAILURE);
    }

    return json;
}

// Chequea una propiedad
void checkProperty(json_t const* property, unsigned int type)
{
    if (!property || type != json_getType( property)) 
    {
        puts("Error, the property is not found.");
        exit(EXIT_FAILURE);
    }
}

// Imprime una propiedad
void printProperty(json_t const* property)
{
	if (!property)
	{
        exit(EXIT_FAILURE);
	}

    char const* name = json_getName(property);
    char const* value = json_getValue(property);

    printf( "\"%s\" : \"%s\"\n", name, value);
}

// Devuelve una propiedad y la chequea
json_t const* getPropertyCheck(json_t const* json, const char* name, unsigned int type)
{
    json_t const* property = json_getProperty(json, name);
    checkProperty(property, type);

    return property;
}

// Devuelve un hijo y lo chequea
json_t const* getChildCheck(json_t const* json, unsigned int type)
{
    json_t const* child = json_getChild(json);

    //if (!child || json_getType(child) != type) printf("Warning!!! The json not found\n");

    return child;
}

// Devuelve un hermano y lo chequea
json_t const* getSiblingCheck(json_t const* json, unsigned int type)
{
    json_t const* sibling = json_getSibling(json);

    //if (!sibling || json_getType(sibling) != type) printf("Warning!!! The json not found\n");

    return sibling;
}

// Imprime un objeto o un array
void dump( json_t const* json ) {

    jsonType_t const type = json_getType( json );
    if ( type != JSON_OBJ && type != JSON_ARRAY ) {
        puts("error");
        return;
    }

    printf( "%s", type == JSON_OBJ? " {": " [" );

    json_t const* child;
    for( child = json_getChild( json ); child != 0; child = json_getSibling( child ) ) {

        jsonType_t propertyType = json_getType( child );
        char const* name = json_getName( child );
        if ( name ) printf(" \"%s\": ", name );

        if ( propertyType == JSON_OBJ || propertyType == JSON_ARRAY )
            dump( child );

        else {
            char const* value = json_getValue( child );
            if ( value ) {
                bool const text = JSON_TEXT == json_getType( child );
                char const* fmt = text? " \"%s\"": " %s";
                printf( fmt, value );
                bool const last = !json_getSibling( child );
                if ( !last ) putchar(',');
            }
        }
    }

    printf( "%s", type == JSON_OBJ? " }": " ]" );

}