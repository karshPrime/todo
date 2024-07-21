
/* ensure_exists.go
 * ensures if certain files or directories exists
 */

package cmd

import(
	"os"
	"fmt"
	"errors"
)

// return full dir path
func ensure_exists_dir(aPath string) string {
	lHome, _ := os.UserHomeDir()
	lPath := lHome + aPath

	_, aPath_exists := os.Stat(lPath)
	if errors.Is(aPath_exists, os.ErrNotExist) {
		lCreateDirErr := os.MkdirAll(lPath, 0770)

		if lCreateDirErr != nil {
			fmt.Fprintln(os.Stderr, "Error EED1:", lCreateDirErr)
			os.Exit(1)
		}
	}
	return lPath
}

// return full file path
func ensure_exists_file(aFile string, aDefaultText []string) string {
	lHome, _ := os.UserHomeDir()
	lFile := lHome + aFile

	_, lConfigFileExists := os.Stat(lFile)
	if errors.Is(lConfigFileExists, os.ErrNotExist) {
		lFileIO, lFileIOError := os.Create(lFile)

		if lFileIOError != nil {
			fmt.Fprintln(os.Stderr, "Error EEF1:", lFileIOError)
			os.Exit(1)
		}
		defer lFileIO.Close()

		for _, lLine := range aDefaultText {
			_, lLineError := fmt.Fprintf(lFileIO, "%s\n", lLine)
			if lLineError != nil {
				fmt.Fprintln(os.Stderr, "Error EEF2:", lLineError)
				return ""
			}
		}
	}
	return lFile
}

