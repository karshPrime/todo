
/* ensure_exists.go
 * ensures if certain files or directories exists
 */

package cmd

import(
	"os"
	"fmt"
	"errors"
)

func ensure_exists_dir(aPath string) {
	home, _:= os.UserHomeDir()
	lPath  := home + aPath

	_, aPath_exists := os.Stat(lPath)
	if errors.Is(aPath_exists, os.ErrNotExist) {
		create_dir_err := os.MkdirAll(lPath, 0770)

		if create_dir_err != nil {
			fmt.Fprintf(os.Stderr, "Error: %v", create_dir_err)
		}
	}
}

func ensure_exists_file(aFile string) {
	home, _:= os.UserHomeDir()
	lFile := home + aFile

	_, config_file_exists := os.Stat(lFile)
	if errors.Is(config_file_exists, os.ErrNotExist) {
		_, create_file_err := os.Create(lFile)

		if create_file_err != nil {
			fmt.Fprintf(os.Stderr, "Error: %v", create_file_err)
		}
	}
}

