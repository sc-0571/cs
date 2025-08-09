from transformers import AutoProcessor, AutoModelForVision2Seq
from PIL import Image
import torch

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"✅ 使用设备: {device}")

processor = AutoProcessor.from_pretrained("ds4sd/SmolDocling-256M-preview")
model = AutoModelForVision2Seq.from_pretrained("ds4sd/SmolDocling-256M-preview")
model.to(device)

# === 修复 boundaries 设备不一致的问题 ===
if hasattr(model, "boundaries"):
    model.boundaries = model.boundaries.to(device)
if hasattr(model, "vision_tower") and hasattr(model.vision_tower, "boundaries"):
    model.vision_tower.boundaries = model.vision_tower.boundaries.to(device)

# 如果 boundaries 在更深层：
for name, module in model.named_modules():
    if hasattr(module, "boundaries"):
        module.boundaries = module.boundaries.to(device)

image = Image.open("sample_page.png").convert("RGB")
prompt = "<image> Convert this page to docling."

raw_inputs = processor(text=prompt, images=image, return_tensors="pt", truncation=True)
allowed_keys = {"input_ids", "attention_mask", "pixel_values", "decoder_input_ids"}
inputs = {k: v.to(device) for k, v in raw_inputs.items() if k in allowed_keys}

with torch.inference_mode():
    outputs = model.generate(**inputs, max_new_tokens=1024)

text = processor.batch_decode(outputs, skip_special_tokens=True)[0]
print("\n📄 Extracted Output:\n")
print(text)
