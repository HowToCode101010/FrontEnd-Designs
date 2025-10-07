<template>
  <div>
    <div>
      <!-- Popular badge -->
      <div v-if="popular">
        <span>Most Popular</span>
      </div>
      
      <!-- Plan details -->
      <div>
        <div>{{ planName }}</div>
        <div>
          <span>$</span>
          <span>{{ currentPrice }}</span>
          <span>/mo</span>
        </div>
        <div>{{ description }}</div>
        <button>Get Started</button>
      </div>
      
      <!-- Features -->
      <div>
        <div>What's included:</div>
        <ul>
          <li v-for="feature in features" :key="feature">
            <span>✓</span>
            <span>{{ feature }}</span>
          </li>
        </ul>
      </div>
    </div>
  </div>
</template>

<script setup>
import { computed } from 'vue'

const props = defineProps({
  popular: {
    type: Boolean,
    default: false
  },
  planName: {
    type: String,
    required: true
  },
  price: {
    type: Object,
    required: true
  },
  description: {
    type: String,
    required: true
  },
  features: {
    type: Array,
    required: true
  },
  isAnnual: {
    type: Boolean,
    default: true
  }
})

const currentPrice = computed(() => {
  return props.isAnnual ? props.price.yearly : props.price.monthly
})
</script>
