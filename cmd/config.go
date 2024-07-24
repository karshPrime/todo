
/* config.go
 * configure how the utility behaves
 */

package cmd

import (
	"os"
	"fmt"
	"reflect"
	"github.com/BurntSushi/toml"
)

//-- local ---------------------------------------------------------------------

type (
	config struct {
		Default		map[string]configDefault
		Repository	map[string]configRepository
		Database	map[string]configDatabase
	}

	configDefault struct {
		Local		bool
		Ignore		bool
		Location	string
	}

	configRepository struct {
		Auth		bool
		Host		string
	}

	configDatabase struct {
		ID			string
		Local		bool
		Ignore		bool
	}
)

func parse_config(aProperty *string, aConfigPath string) string {
	var conf config
	_, lDecodeError := toml.Decode("", &conf)
	if lDecodeError != nil {
		fmt.Fprintln(os.Stderr, "Error ConfigPC:", lDecodeError)
		os.Exit(1)
	}

	typ, val := reflect.TypeOf(conf), reflect.ValueOf(conf)
	for i := 0; i < typ.NumField(); i++ {
		fmt.Printf("%-11s → %v\n", typ.Field(i).Name, val.Field(i).Interface())
	}

	fmt.Printf("to make use of: %v, %v for compile.\n", *aProperty, aConfigPath)
	fmt.Printf("config: %v\n", conf)

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

func Config(aProperty string) string {
	ensure_exists_dir("/.config")
	lConfigPath := ensure_exists_file("/.config/todogo.toml", default_config())

	lConfig := parse_config(&aProperty, lConfigPath)
	if lConfig == "" {
		return default_properties[aProperty]
	}

	return lConfig
}

