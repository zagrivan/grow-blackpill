define start_rtt
  set $_rtt_control_block = &_SEGGER_RTT
  eval "monitor rtt setup %p 128 'SEGGER RTT'", $_rtt_control_block
  monitor rtt start
  monitor rtt server start 12000 0
  monitor rtt server start 12001 1
  monitor rtt server start 12002 2
end

break __rtt_helper_for_gdb_breakpoint
commands
  start_rtt
  clear
end