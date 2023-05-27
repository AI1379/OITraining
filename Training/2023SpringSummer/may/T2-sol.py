def decode(d: int, cipher: str):
    plain = ""
    tmp = d
    for i in range(0, len(cipher), 2):
        plain += chr(int(cipher[i:i+2], 16) ^ tmp)
        tmp = int(cipher[i:i+2], 16)
    return plain

print(decode(int(input()), input()))