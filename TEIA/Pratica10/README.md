## Usage

For running this code, there are 3 arguments to be passed:
* --path or -p : Pass the path of the input file
* --hasheaders or -hh (default: 0) : Pass 0/1 if the input file has headers or not

## Examples

### Input file with no headers
```bash
python calculateSingleLink.py --path ./input-file.csv
```
or
```bash
python calculateSingleLink.py --path ./input-file.csv --hasheaders 0
```

### Input file with headers
```bash
python calculateSingleLink.py --path ./input-file.csv --hasheaders 1
```
