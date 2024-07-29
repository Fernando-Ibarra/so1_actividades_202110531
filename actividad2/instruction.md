### Instruction to run the code every 5 minutes
1. Open the terminal
2. Go to the directory where the code is saved
3. Run the following command:
```bash
crontab -e
```
4. Add the following line to the end of the file:
```bash
*/5 * * * * /bin/bash hw2.sh
```
5. Save the file and exit
6. The code will run every 5 minutes