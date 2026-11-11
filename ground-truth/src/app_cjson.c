/* Fake ECU app: parses and re-serializes a JSON config message with cJSON. */
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

volatile int result;

int main(void)
{
    const char *cfg = "{\"ecu\":\"BMS\",\"fw\":3,\"limits\":{\"vmax\":4.2,\"tmax\":55}}";
    cJSON *root = cJSON_Parse(cfg);
    cJSON *fw = cJSON_GetObjectItemCaseSensitive(root, "fw");
    cJSON_AddStringToObject(root, "lib", cJSON_Version());
    char *out = cJSON_PrintUnformatted(root);
    result = cJSON_IsNumber(fw) && out && strlen(out) > 0;
    free(out);
    cJSON_Delete(root);
    return 0;
}
