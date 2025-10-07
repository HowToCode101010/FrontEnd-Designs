import {fileURLToPath,URL} from 'node:url'
import { defineConfig } from 'vite'
import vue from '@vitejs/plugin-vue'
import tailwindcss from '@tailwindcss/vite'
// https://vite.dev/config/
export default defineConfig({
  plugins: [vue(),tailwindcss()],
  resolve:{
    alias:{
      '@components':fileURLToPath(new URL('./src/components',import.meta.url)),
      '@assets':fileURLToPath(new URL('./src/assets',import.meta.url))
    }
  }
})
