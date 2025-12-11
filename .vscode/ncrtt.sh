# !/bin/bash -e


HOST=127.0.0.1
PORT=12000

# while true; do
#     socat -x "TCP:$HOST:$PORT,retry=2,forever" STDOUT
# done


while true; do
    # Пытаемся подключиться
    # nc 127.0.0.1 12000
    socat "TCP:$HOST:$PORT,retry=2,forever" STDOUT
    ret=$?
    sleep 1
    echo "socat listen..."
    # if [[ $ret -ne 0 ]]; then
    #     sleep 2
    # else
    #     sleep 1
    # fi
done