#include "BaseSerialComposer.hpp"

DataMessage* BaseSerialComposer::get_tx_frame_buf()//TODO: Revise
{
	return frame_bytes;
}

void BaseSerialComposer::configure(tPacketProp packet_config_para)
{
	packet_config= packet_config_para;
}

// void BaseSerialComposer::send_packet(void* data_pointer, size_t data_size, uint8_t msg_type_para)
// { //$$$$$$ QC PASS - without CRC $$$$$$
// //SOURCE: for understanding serial timing https://www.baldengineer.com/when-do-you-use-the-arduinos-to-use-serial-flush.html

// 	uint16_t crc_res;
// 	uint8_t frame_len = (uint8_t)(packet_config.pad_len + packet_config.hdr_len + data_size + packet_config.crc_len + 2);// +2 for EOH & EOP
// 	for (int i = 0; i < packet_config.pad_len; i++)
// 	{
// 		frame_bytes[i] = packet_config.pad_data[i];
// 	}
// 	frame_bytes[packet_config.pad_len] = frame_len;
// 	frame_bytes[packet_config.pad_len + 1] = msg_type_para;
// 	frame_bytes[packet_config.pad_len + 2] = packet_config.pad_EOH;
// 	memcpy(&frame_bytes[packet_config.pad_len + packet_config.hdr_len + 1], data_pointer, data_size); //+1 for EOH
// 	frame_bytes[frame_len - 3] = packet_config.pad_EOP;
// 	crc_res = crc::crc16_ccitt(frame_bytes, frame_len - packet_config.crc_len, (uint8_t)0x00);
// 	frame_bytes[frame_len - 2] = (uint8_t)(crc_res >> 8);
// 	frame_bytes[frame_len - 1] = (uint8_t)crc_res;
// 	emit_message(frame_bytes, frame_len,msg_type::payload);
// }

void BaseSerialComposer::send_packet(DataMessage* t_msg)
{ //$$$$$$ QC PASS - without CRC $$$$$$
//SOURCE: for understanding serial timing https://www.baldengineer.com/when-do-you-use-the-arduinos-to-use-serial-flush.html

	uint16_t crc_res;
	uint8_t frame_len = (uint8_t)(packet_config.pad_len + packet_config.hdr_len + t_msg->getSize() + packet_config.crc_len + 2);// +2 for EOH & EOP
	for (int i = 0; i < packet_config.pad_len; i++)
	{
		frame_bytes->data[i] = packet_config.pad_data[i];
	}
	frame_bytes->data[packet_config.pad_len] = frame_len;
	frame_bytes->data[packet_config.pad_len + 1] = 0x00;
	frame_bytes->data[packet_config.pad_len + 2] = packet_config.pad_EOH;
	memcpy(&frame_bytes->data[packet_config.pad_len + packet_config.hdr_len + 1], (uint8_t*) t_msg, t_msg->getSize()); //+1 for EOH
	frame_bytes->data[frame_len - 3] = packet_config.pad_EOP;
	crc_res = crc::crc16_ccitt(frame_bytes->data, frame_len - packet_config.crc_len, (uint8_t)0x00);
	frame_bytes->data[frame_len - 2] = (uint8_t)(crc_res >> 8);
	frame_bytes->data[frame_len - 1] = (uint8_t)crc_res;
	frame_bytes->len = frame_len;
	emit_message(frame_bytes);
}