
/* config.go
 * configure how the utility behaves
 */

package cmd

import (
	"github.com/BurntSushi/toml"
)

//-- local ---------------------------------------------------------------------

type Config struct {
	Local bool;
	Ignore bool;
	Location string;
}

func default_properties(aProperty *string) string {
	switch *aProperty {
		case "local": return "false"  // by default dont save todo in local dir
		case "ignore": return "false"  // by default dont ignore new todo files
		case "location": return "Documents/Todo" // location for all todo files
	}

	return ""
}

func parse_toml(aProperty *string) string {
	var conf Config
	_, err := toml.Decode(tomlData, &conf)

	return ""
}


//-- global --------------------------------------------------------------------

func Config_Init() {
	ensure_exists_dir("/.config")
	ensure_exists_file("/.config/todogo.toml")
}

func Config_Read(aProperty *string) string {
	lConfig := parse_toml(aProperty)
	if lConfig == "" {
		return default_properties(aProperty)
	}

	return lConfig
}

