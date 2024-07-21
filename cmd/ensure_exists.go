
/* ensure_exists.go
 * ensures if certain files or directories exists
 */

package cmd

import(
	"os"
	"fmt"
	"errors"
)

// return if a new dir had to be created
func ensure_exists_dir(aPath string) bool {
	lHome, _ := os.UserHomeDir()
	lPath := lHome + aPath

	_, aPath_exists := os.Stat(lPath)
	if errors.Is(aPath_exists, os.ErrNotExist) {
		create_dir_err := os.MkdirAll(lPath, 0770)

		if create_dir_err != nil {
			fmt.Fprintf(os.Stderr, "Error EED1: %v", create_dir_err)
		}
		return true
	}
	return false
}

// return if a new file had to be created
func ensure_exists_file(aFile string, aDefaultText []string) bool {
	lHome, _ := os.UserHomeDir()
	lFile := lHome + aFile

	_, lConfigFileExists := os.Stat(lFile)
	if errors.Is(lConfigFileExists, os.ErrNotExist) {
		lFileIO, lFileIOError := os.Create(lFile)

		if lFileIOError != nil {
			fmt.Fprintf(os.Stderr, "Error EEF1: %v", lFileIOError)
			return false
		}
		defer lFileIO.Close()

		for _, lLine := range aDefaultText {
			_, lLineError := fmt.Fprintf(lFileIO, "%s\n", lLine)
			if lLineError != nil {
				fmt.Fprintf(os.Stderr, "Error EEF2: %v", lLineError)
			}
		}

		return true
	}
	return false
}

