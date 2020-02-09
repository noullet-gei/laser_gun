#include "../audio.h"
#ifdef USE_three
/* pour utiliser ce son, declarer :
#define USE_three
extern const unsigned int three[];
*/
const unsigned int three[] = {
5516,   // le nombre d'echantillons
0x03198460, 0x40843208, 0x1a418c26, 0xc3292a3b, 
0xb54a5a86, 0x076994a6, 0x7252c231, 0x1c96a10b, 
0x26354b70, 0xad0c2a58, 0x67301695, 0x6ad0452c, 
0xdc059d00, 0x17954a63, 0x45ed2885, 0x8f29d672, 
0x4a0cd6b1, 0x5a06b52e, 0xe0b96c8b, 0x318b7b1c, 
0x6a43d6f5, 0x4bd0e6b4, 0x22c1210c, 0xa7a52d4b, 
0xa00b6a5c, 0xaa611497, 0x515d022d, 0x9477a9c9, 
0x210d6809, 0xb9cb225c, 0xe7011e80, 0x7258453d, 
0x9ad5910d, 0xc331ae1a, 0x922c1242, 0xaa7b1ab7, 
0x59d8f735, 0xd2911406, 0xd941286a, 0x3dcb53c0, 
0x0f618b05, 0x53daa8b8, 0x1b083030, 0xe6c8915c, 
0x44ac2b1c, 0x8e8bc707, 0x5b9901cd, 0xa7454cf1, 
0xa9d22c9b, 0xc2328ca6, 0x7070a2e4, 0x70d0d530, 
0x16e58e0e, 0xf64e688b, 0x36107b64, 0xed549f05, 
0x405d173d, 0x9d03a5ae, 0x1945959c, 0x464f7aa1, 
0xf4939b28, 0x9dab4a35, 0x2b280e10, 0x46aae7ac, 
0xcd6c72db, 0x75a22179, 0xb4f2d962, 0xa75256e2, 
0x7b3997b4, 0x55cfb569, 0x8975e8f9, 0xace59636, 
0xf33a5af5, 0x29decac5, 0x0ad1bd2d, 0x36b5ec9a, 
0x8e2b0bd2, 0x1339c959, 0x2bca7194, 0xc6165bdb, 
0xf774697a, 0xbde4e742, 0x2f794272, 0x0bce99c5, 
0xda97c671, 0x759cb0fa, 0xc2f2e752, 0xac95d6d4, 
0x8c587994, 0xd698946f, 0x386cb339, 0xad2b8b52, 
0xb0fd5d14, 0x6db6b48c, 0xcb149e67, 0xf965b39a, 
0x6cef4b66, 0xa8a9dd56, 0x7a66c9a4, 0xe2ed9675, 
0xf6aca8ea, 0xa3e554da, 0x513b66d5, 0x8b568fc6, 
0xdaf8dda3, 0x33cb9d9a, 0xdce37653, 0xb115e2f8, 
0x055ab3ad, 0xced2c373, 0xb69e317b, 0x9575505a, 
0x1d9c2ed6, 0x2d42fb85, 0xda988c75, 0x17dbb17d, 
0xd675bd77, 0x2d7bdf1d, 0x375b39d6, 0xe652b46f, 
0x76ceb74a, 0xdebfedeb, 0xdfaee2ba, 0xdc44595c, 
0x6ef996ec, 0x5db4f599, 0xe7f5df6f, 0xb38dced5, 
0xcdfbbaff, 0xce8fb622, 0x10def0ed, 0xa4b4fde3, 
0xef2c4b3c, 0x7d4f5ade, 0x62ba9eb9, 0x1a8def6b, 
0xd55d7b4f, 0xf9bc773c, 0x9e6f5dc5, 0x4d7cedad, 
0x94bf378c, 0xc5eb4631, 0x64cacf5d, 0xed6f94b4, 
0xcf19d733, 0xb5d7756a, 0xb4b77d6a, 0xfde7eb79, 
0x9de3b6a9, 0xef12ddd5, 0x7bb6f5ac, 0xb3f94eeb, 
0xf13bd2d2, 0xead6b6c5, 0x7f3aceb6, 0x5bdc37da, 
0xa6338ae1, 0x5b8bb33b, 0x2cda3796, 0x5b7ccd61, 
0x19966fcd, 0x86b3ca57, 0xd0ede678, 0x8c6695d5, 
0xce78ed73, 0xb0de3352, 0x8be78d67, 0x7187e2d2, 
0xdbead292, 0xe1f2df19, 0x0b8e998b, 0xcd699d5b, 
0x217c6714, 0x5a66d9be, 0xce98bc67, 0x35b52d7c, 
0xcee59a6f, 0xf37bd35b, 0x7bd6d6a6, 0xe678d3e9, 
0x7bbb34c7, 0xaeedadc9, 0x733c6365, 0xde531684, 
0xde52dba4, 0x7cc5b59e, 0xbdacab6f, 0x1d086ef7, 
0x3952d38e, 0x26d69da7, 0xd2739708, 0x9cacfbd1, 
0x212bbef2, 0x0c6738ad, 0xc351dda1, 0x51be9599, 
0xcbf3aa63, 0x2b5deb58, 0x55de34b6, 0xd736c66b, 
0xf794a979, 0xa4a96cd6, 0xf1ad36b9, 0x6963745e, 
0x42d0c8f7, 0x56cdf13c, 0xc5af3e3e, 0x357cd752, 
0x5ace2e81, 0x5f37b5b5, 0xb7bd592d, 0xbe6f8c6c, 
0x7789e359, 0x9ee35aae, 0xd33296a7, 0xb8e6af7c, 
0x95ada9de, 0x68965eb7, 0x46eab7b5, 0xcb3bc569, 
0xd6ee775b, 0x773339e5, 0xa5b7b292, 0xd9c6e8a5, 
0x577bc632, 0x77ef118c, 0x1efb8a63, 0x6f996ad8, 
0xa8631ad0, 0xaa58c5ea, 0xea566b9c, 0xc5533be5, 
0x26faeef8, 0xaaef3ba5, 0x617893b1, 0xb456356d, 
0xb2652c5e, 0x6d6dc739, 0x4c4735bd, 0x3e51cf71, 
0x186b7379, 0xc62d495b, 0x6564529a, 0x3cd6338d, 
0xd696ac97, 0x45be229a, 0xb473bbe6, 0xb539da94, 
0x8c5b12d6, 0xdf359429, 0x357af358, 0x9d6d2a41, 
0x777ad6b5, 0x0a52e9be, 0x5b5ac62b, 0xf505ad8c, 
0xcce75be6, 0xe56b5eb9, 0x5711efbd, 0x5539cef3, 
0x58cb654b, 0x8531ad63, 0x6b9ac1aa, 0xc63e39ce, 
0xd5107d54, 0xfbcdeb36, 0xac656ace, 0x358d6b16, 
0x78cdd8b6, 0xcf37cd73, 0x50946739, 0x8d6b5b8a, 
0xad5be777, 0xac63138c, 0x5b18c635, 0xf7bdf379, 
0xac6f7bde, 0xeb590a56, 0x7deed37d, 0x55aca5ab, 
0xd6c7358c, 0xbe690c5a, 0x6f99d6fb, 0x4a5aa59d, 
0xd2317def, 0xd6c577bc, 0xe6b189d1, 0x1d4a52da, 
0xfae7b973, 0x4eb5acea, 0xb7bd956c, 0xaef79546, 
0xacf64ad9, 0x8a535cd6, 0xef39a4ad, 0xb3cdeb7b, 
0x839d2a51, 0xf359def0, 0xf84af3ce, 0x639ac62e, 
0x3485358b, 0xcde77de7, 0xad6b36b9, 0x9bba53ac, 
0x5639de6f, 0x5ad5eb49, 0xc6b58b6b, 0x737bdf32, 
0x080ef9ce, 0x429084a9, 0x7badf37a, 0x7d0168e7, 
0xa98d7358, 0x7ce5d8e6, 0xdf7bcd73, 0xd4ac5d6a, 
0xad736a62, 0xb39df737, 0xce6a37a5, 0x5b5cc5b1, 
0x79bdef7c, 0x7d1cdcef, 0x696c62d5, 0xdcdf35ad, 
0xd70cc3fb, 0x54b739ac, 0xa3f76c7b, 0xab9eef38, 
0x0b6b39d4, 0xe5d2a5a9, 0x39ef637d, 0xd7337c43, 
0xb5ce631a, 0xbde60fbd, 0x3737bdf7, 0xd6b5ad6b, 
0xad77794a, 0x714be7bd, 0x89739aad, 0x36b0c739, 
0x79def793, 0x86375de2, 0xe54b6310, 0x7ff5cfce, 
0x72b9c833, 0x5ce631ad, 0xee2d5abb, 0x73bcd6fb, 
0xad0e96c5, 0xee8e3ca9, 0x55bf7b9b, 0xc6b99ce1, 
0x5d8e6b98, 0x9def50cb, 0x5ab9de6f, 0x52d630e7, 
0xcdef9852, 0xe97cef7d, 0xcd635c9e, 0x5e56e635, 
0x7bcdf3a7, 0x995f58e7, 0x28eb5b58, 0xdcd77995, 
0x37726ef7, 0x9ad6358d, 0xd5356c6b, 0x6bbde6f3, 
0x284ab3ce, 0x532ca635, 0xbdb3f7bb, 0xdef58bf7, 
0xb5cd62dc, 0x7b5ad0e6, 0xf6cbeeeb, 0x1abde59a, 
0xaba98c8b, 0xfbbce737, 0xbaead3de, 0x439cc4b9, 
0x957dadcd, 0xde67bcee, 0xb2e75031, 0x7862d2a6, 
0xee3bdd6f, 0x79c56b9e, 0x97397a73, 0xa91a6398, 
0x5de6f9cc, 0x9317bddf, 0x56bc31b5, 0xcef37bde, 
0xe19def3b, 0xcd631aad, 0x60c6e6d5, 0x79ad736a, 
0xc5f377d7, 0x2b6d65f4, 0x7ddab1c6, 0xdf79de6f, 
0x76d6efac, 0xc6b58d6b, 0x2bba5ad2, 0x5cd679dd, 
0x62a88523, 0x7965a12a, 0xcef37dd6, 0xb6fd5ebb, 
0xcb631d75, 0xba98b9b5, 0x37be6f5c, 0xad287bbf, 
0xa2ca5a16, 0x5ae6b5b5, 0x4e7b9e7b, 0x1c93b4dc, 
0xd5a5ae4b, 0xf3870e94, 0x18e6b9cb, 0x4ad0ac57, 
0xa58c310a, 0xcef37bde, 0xe78bd779, 0xac6b68a6, 
0xc358a6b5, 0xf7ce691b, 0x7d675aee, 0xa9894ace, 
0x7cca8c84, 0xeefbaec7, 0x1bce337d, 0xe62dccd3, 
0xe96d5a9a, 0xbadf772b, 0x56778c73, 0xd2a62b2a, 
0xd327395a, 0x739de5f7, 0xaaeaf7ce, 0x71daec25, 
0x1296356d, 0xbe737ada, 0x2f5cbebb, 0x2c32d6ad, 
0xd60e8529, 0x798ef35b, 0xa6737be7, 0x39ba6371, 
0x6d435adc, 0xd7389b69, 0x75ae67bc, 0x96250bc9, 
0x29385310, 0x5ce6b59d, 0xdf77be73, 0x1924ab68, 
0xd6edcc53, 0xaf4b6a18, 0x7ce6f7cc, 0xbe95ae6b, 
0xd4a5af2c, 0x2da1224a, 0xef9bdf33, 0xaae6ba4e, 
0x63196c37, 0x1ad6ddca, 0xdaa3096e, 0xf51ceee5, 
0x4a66f6bd, 0xdb19a4b7, 0x368ded89, 0x9ef399e7, 
0x2bace738, 0xccd39586, 0x61dad621, 0x39b36d2b, 
0xabf37cdf, 0xa9485e6d, 0x5852d4a5, 0xdf2fb1e5, 
0x57de6f9c, 0x77772adf, 0x39956b78, 0x2c4356dd, 
0xe6f68da5, 0x34be737b, 0x662b2a5f, 0x216742d7, 
0xa7d732be, 0xe637d0ef, 0x479da35a, 0xddb1a7db, 
0x998d661a, 0xa73710c5, 0x51fbc573, 0xd9abb35c, 
0xa5698bd2, 0x677a91b4, 0x5ae6f7be, 0xc9b7a373, 
0x9acdb158, 0xa75a2e56, 0x4f035b10, 0x7cd6b9ad, 
0xd257cc5b, 0x16cda989, 0x846f0a4e, 0xebbacef7, 
0x3cdaf9c3, 0x5a62ae29, 0xdc9d3579, 0xa6e98d5e, 
0xeb9a51f4, 0xfc8eb7c1, 0x42959224, 0xd2aba568, 
0xbce746cd, 0xef5bd6f5, 0xfad6758d, 0x6f14cd58, 
0x99c7336c, 0x9ca98bd3, 0x6f3cd6ae, 0x29bf2fae, 
0x3acea493, 0x2c84a8cb, 0xbd6f3ac5, 0x6f59e6b7, 
0x3ac175ac, 0x5b34b555, 0xdacc3567, 0xb5512c4a, 
0xf31be675, 0x595eb8ad, 0x4a978333, 0xaa939969, 
0xbd6f78ce, 0x6f19e6b7, 0x1a8a376c, 0x62f2b4c9, 
0x9ac13575, 0x61df0d42, 0xef7bdeb7, 0xf645b78c, 
0x32949424, 0x7684d92b, 0xadeb5bca, 0x2b3ccef7, 
0x2ad6137e, 0x6654b297, 0x1bc6b0ab, 0x81658b33, 
0x6795deee, 0xe7ce35ad, 0x5990a3a2, 0x4fb5a6c9, 
0x9e66dbca, 0x6f69df31, 0x674cb673, 0xebb7842b, 
0xd6eeadb7, 0xc6a4cc6e, 0xecfc3955, 0x3bbeb5bc, 
0x40951bc9, 0x6e751d0a, 0x9d6b06d2, 0xe75bc679, 
0x59cdcfbc, 0x5ed2ad59, 0x83b6af8c, 0xca29b3db, 
0xeb164610, 0x650f338d, 0x424fa557, 0x8e748d52, 
0x9d5af829, 0x6b78cef5, 0x1b49f790, 0x46d67d25, 
0x97a526e8, 0xc5dd8b8a, 0x26f36250, 0x5bb6759b, 
0xcd53ad1f, 0xf2ba6148, 0xba232055, 0xf29addc9, 
0xd7ce3598, 0x5a76a368, 0x1a8e331b, 0xc75b6d3f, 
0xe9b52351, 0x599eeaac, 0x8e339c6b, 0x1152a315, 
0x8404a8b2, 0xeef8d0b1, 0x5a3ef57c, 0xd191ab93, 
0x72ab6529, 0x4c313b60, 0x1ecd4e5a, 0x39327266, 
0xb6359c6b, 0x951d26fa, 0x74e50ac5, 0xeaf9b46e, 
0xfbce75ab, 0x567379ec, 0x55a92b1a, 0xc4ed6bda, 
0x30ca622a, 0xe6b294a5, 0xd6739d5e, 0x708c66f8, 
0x62a6e641, 0xe302b511, 0x79d5f59c, 0xd5ed7d9b, 
0x7284e888, 0x54a0d749, 0x2d485a14, 0x295294a5, 
0xd66f7b45, 0xb25beaf7, 0x539b0335, 0xdd19922b, 
0x58beb35c, 0xc5f58d67, 0x877ad737, 0x53a2e9c1, 
0xa56982cc, 0x0a5a10c4, 0xce539429, 0x6ba1eb36, 
0x41c265c4, 0x6286c224, 0x1ace334b, 0xceb17de3, 
0x51a45b44, 0xbc6542c2, 0x336b55f2, 0x69ab1335, 
0x160eba29, 0x719c5b47, 0x829f3606, 0xe507ca0f, 
0x5a46b29b, 0xd62dbcd3, 0xc37c64d9, 0x8c195a4d, 
0xab085692, 0x4b429474, 0x49d2a525, 0x25ab0ae5, 
0x5ae498ce, 0x94563da9, 0x98c9ab72, 0xbeb53ce8, 
0x6d8ce33a, 0x94e5383e, 0xa91a5170, 0xab4dd69c, 
0x42d285a8, 0x495b9d22, 0x935f37c6, 0x5695ad67, 
0x37c9ed73, 0xceb36ce4, 0x35936b56, 0x9c5939c2, 
0xa6d24dce, 0x4aba9373, 0x59d2b485, 0x5394a528, 
0xa267182e, 0x6516c58f, 0x1845f082, 0xb66f9c0f, 
0xf19d573a, 0x7a9b28d5, 0x6928c1d1, 0x2351ee85, 
0x425774a9, 0x5025e569, 0x4b647629, 0x12f7b5b3, 
0xf7c1cf92, 0xce6f3cdc, 0x73a96754, 0x9068f8cd, 
0x2ef84a34, 0x2ac1525d, 0x5a70b4dd, 0x9254aee9, 
0x6ce137c2, 0x66a5ce69, 0x1045b08b, 0xcce7921b, 
0xb37d62d9, 0x8c5b58be, 0xa2c89d43, 0xa93a0e83, 
0x29d480aa, 0x8e85192a, 0x5c951732, 0xe706c64c, 
0x7838f164, 0xc96f8296, 0xf57ce6f7, 0x8d1b1ab5, 
0x632ac695, 0x37426c35, 0x31948b25, 0x468522eb, 
0x82a4a64a, 0xe625c9cf, 0xd921f459, 0xbe2f7c44, 
0xa39ce2f9, 0x1a6725ce, 0xa3073c70, 0x08325394, 
0x32557525, 0x90845548, 0x7286c73d, 0xdcb3b923, 
0xd73cee62, 0xbe6f0c9e, 0x6bac9b59, 0x346a75d6, 
0xa53949f1, 0x0a4e549c, 0x328f9593, 0x4c929957, 
0x5c20d649, 0xdb05b5cc, 0x38ca3178, 0x26708ce5, 
0x317cd738, 0x73e2f7c6, 0xa5373a2b, 0xea21d28b, 
0x3a6a84d4, 0x4a7a1d10, 0x21c6c7a9, 0xd455b1ad, 
0xf7c5e96b, 0x96715be6, 0x8b9ad738, 0x139cd1a4, 
0x1909aa10, 0x0a108e9a, 0x327054cb, 0x537aa0f7, 
0x23e4e8c5, 0x62d5b56f, 0x18b5b173, 0xd1859c0b, 
0xc28be0e6, 0x449a0845, 0x9ce741ce, 0xd52a2a73, 
0xb5911c20, 0x054154a6, 0x5b6294b5, 0xdef8b631, 
0xb6b5ad7b, 0x458a715c, 0x45241ea6, 0x8aa105b2, 
0x1868394e, 0x069d0453, 0xb9717257, 0xef7bdc58, 
0x6b5ef6bd, 0x14f7b12f, 0xc8018c7b, 0x41428394, 
0x8a4414c5, 0x4814d539, 0xdae3a58d, 0xb7c17171, 
0xb62d6c5e, 0x4b6a4ad7, 0x721cc690, 0x98e721ce, 
0x87450e72, 0x210b4396, 0xe90b0475, 0x6b5af58d, 
0xd2d8b5ef, 0x96acad7b, 0x30cc6a84, 0x8e7398c7, 
0x5318e439, 0xc846894c, 0xd5046a41, 0xc5a97b52, 
0x6f4b5ec2, 0x5156b49d, 0x9eb13c6a, 0x052a0b43, 
0x21cc621d, 0x4b0b14c3, 0x595ea5bd, 0xdeb6b56f, 
0xd4adad3b, 0x114950ce, 0x4c6304e5, 0x7298c629, 
0x16a53166, 0xd58d2312, 0xad6f6ad6, 0x296b5ab7, 
0x409055ad, 0x10c7194c, 0xc2294863, 0x850c4914, 
0x6a1ad602, 0x5ad6d5ad, 0xc6938dab, 0x64114932, 
0x29021290, 0x09119403, 0x29d40299, 0x529485a8, 
0x11a46b49, 0x08442004, 0x8a288c71, 0x410a440c, 
0x4c919903, 0x51252229, 0x88432102, 0x25280641, 
0x1050208c, 0x8a5124a2, 0x5188e400, 0x1488190c, 
0x21104602, 0x1a4a3290, 0x4c309c25, 0x501c2430, 
0x88e1110a, 0x4508c072, 0x01cc4184, 0x0e301023, 
0x11082210, 0x8c010ac2, 0xa5114621, 0x18c02088, 
0xc4400442, 0x000c4310, 0x0c431080, 0x42000600, 
0x2a460104, 0x42110822, 0x31806300, 0x84031884, 
0x00088620, 0x08021080 };
#endif
