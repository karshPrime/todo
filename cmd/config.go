
/* config.go
 * configure how the utility behaves
 */

package cmd

import (
	"fmt"
	"github.com/BurntSushi/toml"
)

//-- local ---------------------------------------------------------------------

type ConfigDefault struct {
	Local		bool
	Ignore		bool
	Location	string
}

type ConfigRepository struct {
	Auth		bool
	Host		string
}

type ConfigDatabase struct {
	ID			string
	Local		bool
	Ignore		bool
}

func parse_config(aProperty *string) string {
	// var conf Config
	// _, err := toml.Decode(tomlData, &conf)

	return ""
}

var default_properties = map [string]string {
	"local" : "false",      // by default dont save todo in local dir
	"ignore" : "false",      // by default dont ignore new todo files
	"location" : "\"Documents/Todo\"", // location for all todo files
}

func default_config() []string {
    result := []string{
        "# ToDo.go",
        "",
        "[defaults]",
    }

    for key, value := range default_properties {
        result = append(result, fmt.Sprintf("%s = %s", key, value))
    }

    result = append(result, "", "[repository]", "Authenticated = false")

    return result
}


//-- global --------------------------------------------------------------------

func Config_Init() {
	ensure_exists_dir("/.config")
	ensure_exists_file("/.config/todogo.toml", default_config())
}

func Config_Read(aProperty *string) string {
	lConfig := parse_config(aProperty)
	if lConfig == "" {
		return default_properties[*aProperty]
	}

	return lConfig
}

