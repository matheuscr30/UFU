## Usage

For running this code, there are 2 arguments to be passed:
* --path or -p : Pass the path of the input file
* --hasheaders or -hh (default: 0) : Pass 0/1 if the input file has headers or not
* --distance or -d: Pass 1 for manhattan distance and 2 for euclidean distance

## Examples

### Input file with no headers
```bash
python calculateDistance.py --path ./input-file.csv --distance 2
```
or
```bash
python calculateDistance.py --path ./input-file.csv --hasheaders 0 --distance 1
```

### Input file with headers
```bash
python calculateDistance.py --path ./input-file.csv --hasheaders 1 -d 1
```
