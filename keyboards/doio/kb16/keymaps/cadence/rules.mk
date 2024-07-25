# Online configurators enabled
VIA_ENABLE = yes	# unsure if both can be enabled simultaneously, or if VIA has to be enabled for VIAL; thompson-vii (GitHub) firmware used as reference has both
VIAL_ENABLE = yes

# Link Time Optimization; takes longer to compile, but helps achieve smallest firmware size
LTO_ENABLE = yes

# Encoder enabled
# ENCODER_ENABLE = yes	# thompson-vii (GitHub) firmware used as reference has both; unclear if needed
ENCODER_MAP_ENABLE = yes

# Tap Dance enabled
TAP_DANCE_ENABLE = yes

# Send String (enabled by default; included for completeness)
SEND_STRING_ENABLE = yes

# EEPROM Driver (vendor by default; included for completeness)
EEPROM_DRIVER = vendor
