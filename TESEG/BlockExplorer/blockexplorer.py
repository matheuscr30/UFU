from blockchain import blockexplorer
import time

if __name__ == '__main__':
    accounts = {}
    block_limit = 1000

    for height in range(0, block_limit+1):
        blocks = blockexplorer.get_block_height(height)
        for block in blocks:
            print(f'Height: {block.height}')
            for transaction in block.transactions:
                for input in transaction.inputs:
                    if not hasattr(input, 'address') and not hasattr(input, 'value'):
                        # Coinbase transaction
                        continue
                    elif hasattr(input, 'address'):
                        account_value = accounts.get(input.address, 0)
                        accounts[input.address] = account_value - input.value

                for output in transaction.outputs:
                    account_value = accounts.get(output.address, 0)
                    accounts[output.address] = account_value + output.value
        time.sleep(0.7)

    output_file = open('result.txt', 'w')

    count_equal_value = 0
    count_greater_value = 0
    count_lower_value = 0

    for address, value in accounts.items():
        actual_address = blockexplorer.get_address(address, limit=1)
        time.sleep(0.7)

        if value == actual_address.final_balance:
            count_equal_value += 1
        elif actual_address.final_balance > value:
            count_greater_value += 1
        else:
            count_lower_value += 1

        output_file.write(f'Address: {address}' + '\n')
        output_file.write(f'Balance after {block_limit} Blocks: {value}' + '\n')
        output_file.write(f'Balance now: {actual_address.final_balance}' + '\n')
        output_file.write('\n')

    output_file.write(f'With {block_limit} blocks' + '\n')
    output_file.write(f'{len(accounts)} were involved in the transactions of the first {block_limit} blocks' + '\n')
    output_file.write(f'Addresses that have the same balance now: {count_equal_value}' + '\n')
    output_file.write(f'Addresses that had less balance than now: {count_greater_value}' + '\n')
    output_file.write(f'Addresses that had more balance than now: {count_lower_value}' + '\n')

    output_file.close()
